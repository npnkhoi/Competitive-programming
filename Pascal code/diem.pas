var f:text;
        point, ans: real;
begin
        assign(f, 'diemso.dat'); reset(f);
        while not(eof(f)) do
        begin
                read(f, point);
                if (point > ans) then ans := point;
        end;
        writeln(ans:0:3)
end.