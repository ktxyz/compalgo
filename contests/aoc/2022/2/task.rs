use std::io::{self, BufRead};

fn main() {
    let mut ans = 0;
    let mut lines = io::stdin().lock().lines();
    while let Some(line) = lines.next() {
        let str_input: String = line.unwrap();
        let last_input: Vec<char> = str_input.chars().collect();
        if (last_input[0] as u32 - 'A' as u32) == (last_input[2] as u32 - 'X' as u32) {
            ans += 3 + last_input[2] as u32 - 'X' as u32 + 1;
        } else {
            let ca: char = last_input[0];
            match ca {
                'A'..='A' => {
                    if (last_input[2] as u32) == ('Y' as u32) {
                        ans += 8;
                    } else {
                        ans += 3;
                    }
                }
                'B'..='B' => {
                    if (last_input[2] as u32) == ('Z' as u32) {
                        ans += 9;
                    } else {
                        ans += 1;
                    }
                }
                'C'..='C' => {
                    if (last_input[2] as u32) == ('X' as u32) {
                        ans += 7;
                    } else {
                        ans += 2;
                    }
                }
                _ => println!("FUCK OFF"),
            }
        }
    }

    println!("{}\n", ans);
}
