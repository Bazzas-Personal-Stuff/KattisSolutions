// https://open.kattis.com/problems/fizzbuzz

use std::io;

fn main() {
    let mut in_string = String::new();

    io::stdin().read_line(&mut in_string).ok().expect("read error");

    let inputs:Vec<i32> = in_string
        .split_whitespace()
        .map(|s| s.parse().expect("parse error"))
        .collect();

    let x = inputs[0];
    let y = inputs[1];
    let n = inputs[2];

    for i in 1..n + 1{
        let mut fits = false;
        if i % x == 0 {
            print!("Fizz");
            fits = true;
        }
        if i % y == 0 {
            print!("Buzz");
            fits = true;
        }
        if !fits {
            print!("{}", i);
        }
        print!("\n");
    }
}
