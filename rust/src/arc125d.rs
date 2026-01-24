use std::io::{self, BufRead, StdinLock};
use std::{i64, str};
pub struct Scanner<'a> {
    stdin: StdinLock<'a>,
    buf: Vec<u8>,
    pos: usize,
}
impl<'a> Scanner<'a> {
    pub fn new(stdin: StdinLock<'a>) -> Self {
        Self {
            stdin,
            buf: Vec::new(),
            pos: 0,
        }
    }
    pub fn readi64(&mut self) -> i64 {
        self.sksp();
        let st = self.pos;
        while self.pos < self.buf.len() {
            let bt = self.buf[self.pos];
            if bt.is_ascii_digit() || (self.pos == st && (bt == b'-' || bt == b'+')) {
                self.pos += 1;
            } else {
                break;
            }
        }
        if self.pos == st {
            panic!("缺少数字");
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buf[st..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn readf64(&mut self) -> f64 {
        self.sksp();
        let st = self.pos;
        while self.pos < self.buf.len() {
            let bt = self.buf[self.pos];
            if bt.is_ascii_digit()
                || bt == b'.'
                || bt == b'e'
                || bt == b'E'
                || bt == b'+'
                || bt == b'-'
                || (self.pos == st && (bt == b'-' || bt == b'+'))
            {
                self.pos += 1;
            } else {
                break;
            }
        }
        let num_str = unsafe { str::from_utf8_unchecked(&self.buf[st..self.pos]) };
        num_str.parse().unwrap()
    }
    pub fn readstring(&mut self) -> String {
        self.sksp();
        let st = self.pos;
        while self.pos < self.buf.len() && !self.buf[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        let word = unsafe { str::from_utf8_unchecked(&self.buf[st..self.pos]) };
        word.to_string()
    }
    pub fn readchar(&mut self) -> char {
        self.ensure_buf(1);
        let bt = self.buf[self.pos];
        self.pos += 1;
        bt as char
    }
    fn sksp(&mut self) {
        self.ensure_buf(1);
        while self.pos < self.buf.len() && self.buf[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        if self.pos >= self.buf.len() {
            self.buf.clear();
            self.stdin.read_until(b'\n', &mut self.buf).unwrap();
            self.pos = 0;
            self.sksp();
        }
    }
    fn ensure_buf(&mut self, n: usize) {
        while self.buf.len() - self.pos < n {
            let mut temp = Vec::new();
            self.stdin.read_until(b'\n', &mut temp).unwrap();
            self.buf.extend(temp);
        }
    }
    pub fn peek_char(&mut self) -> Option<char> {
        self.sksp();
        if self.pos < self.buf.len() {
            Some(self.buf[self.pos] as char)
        } else {
            None
        }
    }
    pub fn has_next(&mut self) -> bool {
        self.sksp();
        self.pos < self.buf.len()
    }
}
pub fn scanner() -> Scanner<'static> {
    let stdin = io::stdin();
    Scanner::new(stdin.lock())
}
struct FenwickTree {
    tree: Vec<i64>,
    n: usize,
}
impl FenwickTree {
    fn new(n: usize) -> Self {
        FenwickTree {
            tree: vec![0; n + 1],
            n,
        }
    }
    fn lowbit(x: usize) -> usize {
        x & (!x + 1)
    }
    fn add(&mut self, mut pos: usize, val: i64) {
        while pos <= self.n {
            self.tree[pos] += val + 998244353;
            self.tree[pos] %= 998244353;
            pos += Self::lowbit(pos);
        }
    }
    fn ask(&self, mut pos: usize) -> i64 {
        let mut sum = 0;
        while pos > 0 {
            sum += self.tree[pos];
            sum %= 998244353;
            pos -= Self::lowbit(pos);
        }
        sum
    }
    fn query(&self, l: usize, r: usize) -> i64 {
        if l == 0 {
            self.ask(r)
        } else {
            (self.ask(r) - self.ask(l - 1) + 998244353) % 998244353
        }
    }
}
fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let n = sc.readf64() as usize;
    /*    let mut t=vec![0i64;n+1];
    fn lowbit(x:i64) -> i64 {
        x&(-x)
    }
    fn add(pl:i64,val:i64,t:&mut Vec<i64>,n:i64) -> () {
        let mut pl=pl;
        while pl <= n {
            t[pl as usize]+=val;
            pl+=lowbit(pl);
        }
    }
    fn qur(pl:i64,t:&Vec<i64>) -> i64 {
        let mut ret:i64=0i64;
        let mut pl=pl;
        while pl > 0 {
            ret+=t[pl as usize];
            pl-=lowbit(pl);
        }
        ret
    }*/
    let mut a = vec![0usize; n + 1];
    let mut ed = vec![-1i64; n + 1];
    let mut dp = FenwickTree::new(n + 1);
    fn max(x: i64, y: i64) -> i64 {
        if x > y { x } else { y }
    }
    for i in 1..=n {
        a[i] = sc.readi64() as usize;
        if ed[a[i]] == -1 {
            dp.add(i, 1i64);
        }
        dp.add(i, dp.query(max(ed[a[i]], 0i64) as usize, i - 1));
        dp.add(
            ed[a[i]] as usize,
            -dp.query(max(ed[a[i]], 0i64) as usize, max(ed[a[i]], 0i64) as usize),
        );
        ed[a[i]] = i as i64;
    }
    print!("{}", dp.ask(n));
}
