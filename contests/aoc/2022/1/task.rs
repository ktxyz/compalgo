use std::io::{self, BufRead};

fn main() {
    let mut a_1 = 0;
    let mut a_2 = 0;
    let mut a_3 = 0;
    let mut a_c = 0;
    let mut lines = io::stdin().lock().lines();
    while let Some(line) = lines.next() {
        let last_input = line.unwrap();

        if last_input.len() == 0 {
            if a_c > a_1 {
                a_3 = a_2;
                a_2 = a_1;
                a_1 = a_c;
            } else if a_c > a_2 {
                a_3 = a_2;
                a_2 = a_c;
            } else if a_c > a_3 {
                a_3 = a_c;
            }
            a_c = 0;
        } else {
            a_c += last_input.parse::<i32>().unwrap();
        }
    }

    println!("{} {}\n", a_1, a_1 + a_2 + a_3);
}
