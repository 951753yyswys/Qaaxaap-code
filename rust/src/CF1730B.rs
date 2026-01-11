use std::io;
fn min(x:i32,y:i32)->i32
{
    if x>y {y} else {x}
}
fn max(x:i32,y:i32)->i32
{
    if x<y {y} else {x}
}
fn main()
{
    let mut input=String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t:u32=input.trim().parse().unwrap();
    for _ in 0..t
    {
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let n:usize=input.trim().parse().unwrap();
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let x:Vec<i32>=input
            .split_whitespace()
            .take(n)  
            .map(|s|s.parse().unwrap())
            .collect();
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let t:Vec<i32>=input
            .split_whitespace()
            .take(n)
            .map(|s|s.parse().unwrap())
            .collect();
        let mut mi:i32=0x7fffffff;
        let mut mx:i32=-0x7fffffff;
        for i in 0..n
        {
            mi=min(x[i]-t[i],mi);
            mi=min(x[i]+t[i],mi);
            mx=max(x[i]-t[i],mx);
            mx=max(x[i]+t[i],mx);
        }
        print!("{}\n",((mi+mx)as f64)/2.0);
    }
}
