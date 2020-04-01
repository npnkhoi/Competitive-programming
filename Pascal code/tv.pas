uses math;
const fin='tv.inp'; fon='tv.out';
var l,r,t:array[0..30003] of longint;
    n,s,kq,i,j:longint;
    fi,fo:text;
procedure start;
begin
        assign(fi,fin); reset(fi);
        assign(fo,fon); rewrite(fo);
        readln(fi,n);
        for i:= 1 to n do
        begin
                readln(fi,l[i],r[i]);
                inc(t[l[i]]); dec(t[r[i]]);
        end;
end;
procedure main;
begin
    s:= 0; kq:= 0;
    for i:= 1 to n do
    begin
        inc(s,t[i]);
        kq:= max(kq,s);
    end;
    writeln(fo,kq);
end;
begin
    start;
    main;
    close(fi); close(fo);
end.