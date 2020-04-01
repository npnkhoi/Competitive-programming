//uses crt;
const  mo=trunc(1e9);
var n,i:longint;
    f:array[-3..1001] of int64;
    a:array[-3..1001] of 0..2;
procedure start;
begin
    readln(n);
    for i:= 1 to n do read(a[i]);
end;
procedure main;
begin
    a[0]:= 0; a[-1]:= 2; a[-2]:= 2; a[-3]:= 2; a[n+1]:= 0;
    f[0]:= 1; f[-1]:= 0; f[-2]:= 0; f[-3]:= 0;
    for i:= 1 to n+1 do
    case a[i] of
    0:
    begin
        if a[i-1]<2 then f[i]:= (f[i]+f[i-1]) mod mo;
        if a[i-2]<2 then f[i]:= (f[i]+f[i-2]) mod mo;
        if a[i-3]=0 then f[i]:= (f[i]+f[i-3]) mod mo;
    end;
    1: f[i]:= f[i-1];
    2: f[i]:= 0;
    end;
end;
begin
    start;
    main;
    writeln(f[n+1]);
end.
