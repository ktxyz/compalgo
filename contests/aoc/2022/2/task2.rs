use std::io::{self, BufRead};

fn main() {
    let mut ans = 0;
    let mut lines = io::stdin().lock().lines();
    while let Some(line) = lines.next() {
        let str_input: String = line.unwrap();
        let last_input: Vec<char> = str_input.chars().collect();
        let ca: char = last_input[2];
        match ca {
            'X'..='X' => {
                ans += ((last_input[0] as u32 - 'A' as u32) + 2) % 3 + 1;
                println!("X: {}\n", ((last_input[0] as u32 - 'A' as u32) + 2) % 3 + 1);
            }
            'Y'..='Y' => {
                ans += 4 + last_input[0] as u32 - 'A' as u32;
                println!("Y: {}\n", ((last_input[0] as u32 - 'A' as u32) + 1));
            }
            'Z'..='Z' => {
                ans += 6 + ((last_input[0] as u32 - 'A' as u32) + 1) % 3 + 1;
                println!("Z: {}\n", ((last_input[0] as u32 - 'A' as u32) + 1) % 3 + 1);
            }
            _ => println!("FUCK OFF"),
        }
    }

    println!("{}\n", ans);
}
