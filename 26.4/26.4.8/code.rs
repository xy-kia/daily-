struct Robot {
    x: i32,                // 当前x坐标
    y: i32,                // 当前y坐标
    dir: &'static str,     // 当前方向
    width: i32,            // 网格宽度
    height: i32,           // 网格高度
    perimeter: i32,        // 外圈总步数（优化用）
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Robot {

    fn new(width: i32, height: i32) -> Self {
        // 计算外圈总步数
        let perimeter = 2 * (width - 1) + 2 * (height - 1);
        Robot {
            x: 0,
            y: 0,
            dir: "East",
            width,
            height,
            perimeter,
        }
    }
    
    fn step(&mut self, mut num: i32) {
        if self.perimeter == 0 {
            return; // 网格只有一个格子，无法移动
        }
        // 优化：跳过完整的圈，只走剩余步数
        num %= self.perimeter;

        for it in 0..num {
            self.step_one();
        }

        if num == 0 {
            // 只有从非原点走回原点时，才改方向
            if (self.x == 0 && self.y == 0) {
                self.dir = "South";
            }
            return;
        }
    }

    fn step_one(&mut self) {
        let (next_x, next_y) = self.next_pos();
        // 判断下一步是否越界
        if self.is_out_of_bounds(next_x, next_y) {
            // 逆时针转90度
            self.turn_counter_clockwise();
            // 转向后重新计算下一步位置
            let (new_x, new_y) = self.next_pos();
            self.x = new_x;
            self.y = new_y;
        } else {
            // 不越界，直接移动
            self.x = next_x;
            self.y = next_y;
        }
    }

    // 获取当前方向的下一步坐标
    fn next_pos(&self) -> (i32, i32) {
        match self.dir {
            "East" => (self.x + 1, self.y),
            "North" => (self.x, self.y + 1),
            "West" => (self.x - 1, self.y),
            "South" => (self.x, self.y - 1),
            _ => (self.x, self.y),
        }
    }

    // 判断坐标是否越界
    fn is_out_of_bounds(&self, x: i32, y: i32) -> bool {
        x < 0 || x >= self.width || y < 0 || y >= self.height
    }

    // 逆时针旋转90度
    fn turn_counter_clockwise(&mut self) {
        self.dir = match self.dir {
            "East" => "North",
            "North" => "West",
            "West" => "South",
            "South" => "East",
            _ => self.dir,
        };
    }
    
    fn get_pos(&self) -> Vec<i32> {
        vec![self.x, self.y]
    }
    
    fn get_dir(&self) -> String {
        self.dir.to_string()
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * let obj = Robot::new(width, height);
 * obj.step(num);
 * let ret_2: Vec<i32> = obj.get_pos();
 * let ret_3: String = obj.get_dir();
 */