uses math;
const inf=high(longint);
var fi,fo:text;
    n,i,kq:longint;
    a,b:array[0..100001] of longint;
    s:ansistring;
procedure start;
begin
    assign(fi,'beautiful.inp'); reset(fi);
    assign(fo,'beautiful.out'); rewrite(fo);
    readln(fi,s);
    n:= length(s);
end;
procedure build;
begin
    a[0]:= 0;
    for i:= 1 to n do if (s[i]>='a') and (s[i]<='z') then
    a[i]:= a[i-1]+ord(s[i]) else a[i]:= a[i-1];
    b[n+1]:= 0;
    for i:= n downto 1 do if (s[i]>='A') and (s[i]<='Z') then
    b[i]:= b[i+1]+ord(s[i]) else b[i]:= b[i+1];
end;
procedure main;
begin
    kq:= inf;
    for i:= 0 to n do kq:= min(kq,a[i]+b[i+1]);
    writeln(fo,kq);
end;
begin
    start;
    build;
    main;
    close(fi); close(fo);
end.
