const fin='ngoac.inp'; fon='ngoac.out';
var s:ansistring;
    stack:array[0..103] of longint;
    n,point,i:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,s);
    n:= length(s);
end;
procedure push(x:longint);
begin
    inc(point);
    stack[point]:= x;
end;
procedure main;
begin
    point:= 0;
    for i:= 1 to n do
    begin
        if s[i]='(' then push(i)
        else
        begin
            writeln(fo,stack[point],' ',i);
            dec(point);
        end;
    end;
end;
begin
    start;
    main;
    close(fi); close(fo);
end.