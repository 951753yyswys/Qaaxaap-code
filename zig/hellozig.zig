const std = @import("std");

/// 读一行（不包含 '\n'）。EOF 返回 null。
pub fn readLine(r: *std.Io.Reader) !?[]const u8 {
    if (r.takeDelimiterExclusive('\n')) |line| {
        // takeDelimiterExclusive 不包含分隔符，但分隔符仍留在流里，需要丢掉
        r.toss(1);
        return line;
    } else |err| switch (err) {
        error.EndOfStream => return null,
        else => return err,
    }
}

/// 从一行里解析一个值：
/// - 整数：parseInt
/// - 浮点：parseFloat
/// - 字符串：返回去掉两端空白后的 slice
pub fn readValueLine(comptime T: type, r: *std.Io.Reader) !T {
    const line_opt = try readLine(r);
    //if (line_opt == null) return null;

    const line = std.mem.trim(u8, line_opt.?, " \t\r");
    if (line.len == 0) return error.InvalidValue;

    return switch (@typeInfo(T)) {
        .int => try std.fmt.parseInt(T, line, 10),
        .float => try std.fmt.parseFloat(T, line),
        .pointer => |p| blk: {
            // 只支持 []const u8 / []u8 这种“字符串切片”
            if (p.size != .slice or p.child != u8) @compileError("readValueLine: only supports string slices like []const u8");
            break :blk @as(T, line);
        },
        else => @compileError("readValueLine: unsupported type"),
    };
}

/// 读一行并按空白切分成 token，然后逐个喂给回调（也算泛型封装，写竞赛很爽）
pub fn forEachTokenInLine(
    r: *std.Io.Reader,
    comptime F: type,
    f: F,
) !bool {
    const line_opt = try readLine(r);
    if (line_opt == null) return false;

    var it = std.mem.tokenizeAny(u8, line_opt.?, " \t\r");
    while (it.next()) |tok| {
        try f(tok);
    }
    return true;
}

pub fn main() !void {
    var in_buf: [1024]u8 = undefined;
    //var out_buf: [1024]u8 = undefined;
    var stdin_wrap = std.fs.File.stdin().reader(&in_buf);
    //var stdout_wrap = std.fs.File.stdout().writer(&out_buf);
    const r: *std.Io.Reader = &stdin_wrap.interface;
    //const w: *std.Io.Writer = &stdout_wrap.interface;
    const n:i65535=(@as(i65535,1)<<30000)-1;
    const m:i65535=(@as(i65535,1)<<33555)-1;
    const a: i32 = try readValueLine(i32, r);
    const b: i32 = try readValueLine(i32, r);
    const ans:i65535=(a^n)*(b^m);
    std.debug.print("{}\n {}\n {}\n", .{n,m,ans});
}
