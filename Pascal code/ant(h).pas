type int = longint; rc = record x, y: int end;
const
    fi = 'ANT.INP';
    fo = 'ANT.OUT';
    maxboard = trunc(1e3);
    inf = trunc(1e8);
var dx: array[1..4] of shortint = (0, 0, 1, -1);
    dy: array[1..4] of shortint = (1, -1, 0, 0);
    board: array[-maxboard..maxboard, -maxboard..maxboard] of boolean;
    queue: array[0..inf] of rc;
    c, s, left, right: int;
/////////////////////////
procedure linput;
var i, x, y: int;
    f: text;
begin
    assign(f, fi); reset(f);
    read(f, c, s);
    for i := 1 to c do begin
        readln(f, x, y);
        board[x, y] := true;
    end;
    close(f);
end;
/////////////////////////
procedure push(x, y: int);
begin
    right := right+1;
    queue[right].x := x;
    queue[right].y := y;
end;
/////////////////////////
function pop: rc;
begin
    left := left+1;
    exit(queue[left-1]);
end;
/////////////////////////
procedure solution;
var count, res, lenqueue, i, x, y: int;
    temp: rc;
begin
    board[0, 0] := true; left := 1; right := 0; res := 0;
    repeat
        count := count+1; lenqueue := right-left+1;
        while (lenqueue > 0) do begin
            lenqueue := lenqueue-1;
            temp := pop;
            for i := 1 to 4 do begin
                x := temp.x+dx[i];
                y := temp.y+dy[i];
                if (not board[x, y]) then begin
                    push(x, y);
                    res := res+1;
                    board[x, y] := true;
                end;
            end;
        end;
    until (count = s);
    write(res);
end;
////////////////////////
begin
    linput;
    solution;
end.
