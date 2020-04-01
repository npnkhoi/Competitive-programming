uses math;
var n,i,m,s:longint;
    a:array[0..100001] of longint;
begin
    readln(n);
    for i:= 1 to n do read(a[i]);
    m:= a[1]; s:= a[2]-a[1];
    for i:= 3 to n do
    begin
        m:= min(m,a[i-1]);
        s:= max(s,a[i]-m);
    end;
    writeln(s);
end.