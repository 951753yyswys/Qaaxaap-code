use std::io::{self, BufRead, StdinLock};
use std::{i64, str};

pub struct Scanner<'a> {
    stdin: StdinLock<'a>,
    buffer: Vec<u8>,
    pos: usize,
}
impl<'a> Scanner<'a> {
    pub fn new(stdin: StdinLock<'a>) -> Self {
        Self { stdin, buffer: Vec::new(), pos: 0 }
    }
    pub fn next_i64(&mut self) -> i64 {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buffer.len() {
            let byte = self.buffer[self.pos];
            if byte.is_ascii_digit() || (self.pos == start && (byte == b'-' || byte == b'+')) {
                self.pos += 1;
            } else {
                break;
            }
        }
        if self.pos == start { panic!("没有读取到数字"); }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn next_f64(&mut self) -> f64 {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buffer.len() {
            let byte = self.buffer[self.pos];
            if byte.is_ascii_digit()
                || byte == b'.'
                || byte == b'e'
                || byte == b'E'
                || byte == b'+'
                || byte == b'-'
                || (self.pos == start && (byte == b'-' || byte == b'+'))
            {
                self.pos += 1;
            } else {
                break;
            }
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn next_string(&mut self) -> String {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buffer.len() && !self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        let word = unsafe { str::from_utf8_unchecked(&self.buffer[start..self.pos]) };
        word.to_string()
    }
    pub fn next_char(&mut self) -> char {
        self.ensure_buffer(1);
        let byte = self.buffer[self.pos];
        self.pos += 1;
        byte as char
    }
    fn skip_whitespace(&mut self) {
        self.ensure_buffer(1);
        while self.pos < self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        if self.pos >= self.buffer.len() {
            self.buffer.clear();
            self.stdin.read_until(b'\n', &mut self.buffer).unwrap();
            self.pos = 0;
            self.skip_whitespace();
        }
    }
    fn ensure_buffer(&mut self, n: usize) {
        while self.buffer.len().saturating_sub(self.pos) < n {
            let mut temp = Vec::new();
            self.stdin.read_until(b'\n', &mut temp).unwrap();
            self.buffer.extend(temp);
        }
    }
    pub fn peek_char(&mut self) -> Option<char> {
        self.skip_whitespace();
        if self.pos < self.buffer.len() { Some(self.buffer[self.pos] as char) } else { None }
    }
    pub fn has_next(&mut self) -> bool {
        self.skip_whitespace();
        self.pos < self.buffer.len()
    }
}

pub fn scanner() -> Scanner<'static> {
    let stdin = io::stdin();
    Scanner::new(stdin.lock())
}

fn main() {
    #[derive(Clone, Copy)]
    struct pair { first: i64, second: i64 }
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let n = scanner.next_i64() as usize;
    let mut a = vec![0usize; n];
    for i in 0..n {
        a[i] = scanner.next_i64() as usize;
    }
    let mut fis = vec![-1i64; n + 1];
    let mut sec = vec![-1i64; n + 1];
    for i in 0..n {
        let v = a[i];
        if fis[v] == -1 { fis[v] = i as i64; }
        sec[v] = i as i64;
    }
    let mut s = Vec::<pair>::new();
    for v in 1..=n {
        if fis[v] != -1 && fis[v] < sec[v] {
            s.push(pair { first: fis[v], second: sec[v] });
        }
    }
    if s.is_empty() {
        println!("0");
        return;
    }
    s.sort_by(|x, y| {
        if x.first != y.first { x.first.cmp(&y.first) } else { y.second.cmp(&x.second) }
    });
    let mut t = Vec::<pair>::new();
    for seg in s {
        if t.is_empty() || seg.second > t.last().unwrap().second {
            t.push(seg);
        }
    }
    s = t;
    let mut ans: i64 = 0;
    let mut now = Vec::<pair>::new();
    let mut r: i64 = -1;   
    for seg in s {
        if now.is_empty() {
            now.push(seg);
            r = seg.second;
        } else if seg.first > r {
            let cnt = now.last().unwrap().second - now[0].first + 1;
            let mut res: i64 = 0;   
            let mut nowr: i64 = -1;    
            for i in 0..now.len() {
                if i == now.len() - 1 || now[i + 1].first > nowr {
                    res += 1;
                    nowr = now[i].second;
                }
            }
            ans += cnt - (res + 1);
            now.clear();
            now.push(seg);
            r = seg.second;
        } else {
            now.push(seg);
            r = seg.second;
        }
    }
    if !now.is_empty() {
        let cnt = now.last().unwrap().second - now[0].first + 1;
        let mut res: i64 = 0;
        let mut nowr: i64 = -1;
        for i in 0..now.len() {
            if i == now.len() - 1 || now[i + 1].first > nowr {
                res += 1;
                nowr = now[i].second;
            }
        }
        ans += cnt - (res + 1);
    }
    println!("{}", ans);
}

