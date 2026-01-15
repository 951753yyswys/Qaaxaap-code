const std = @import("std");
const io = std.io;
const fs = std.fs;

pub fn main() !void {
    //const stdin = io.getStdIn().reader();
    //const stdout = io.getStdOut().writer();
    const n:i65535=(@as(i65535,1)<<30000)-1;
    const m:i65535=(@as(i65535,1)<<33555)-1;
    std.debug.print("{}\n {}\n {}\n", .{n,m,n*m});
}
