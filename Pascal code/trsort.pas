uses math;
var a,dt,dg:array[0..2001] of longint;
    i,j,n,kq:longint;
    f:text;
begin
    assign(f,'trsort.inp'); reset(f);
    readln(f,n);
    for i:= 1 to n do read(f,a[i]);
    close(f);
    for i:= 1 to n do begin dt[i]:= 1; dg[i]:= 1; end;
    for i:= n downto 1 do
    for j:= i+1 to n do
        begin
            if (a[i]<=a[j]) then dt[i]:= max(dt[i],dt[j]+1);
            if (a[i]>=a[j]) then dg[i]:= max(dg[i],dg[j]+1);
        end;
    kq:= 0;
    assign(f,'trsort.out'); rewrite(f);
    for i:= 1 to n do kq:= max(kq,dt[i]+dg[i]-1);
    writeln(f,kq);
    close(f);
end.