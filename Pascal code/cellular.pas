uses math;
var fi,fo:text;
    kq,i,m,n:longint;
    a,b:array[0..100001] of longint;

procedure start;
begin
    assign(fi,'cellular.inp'); reset(fi);
    assign(fo,'cellular.out'); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to n do read(fi,a[i]);
    for i:= 1 to m do read(fi,b[i]);
end;
function nearest(x:longint):longint;
var l,r,mid,s1,s2:longint;
begin
    l:= 1;
    r:= m;
    while l<r do
    begin
        mid:= (l+r) div 2;
        if b[mid]-x>=0 then r:= mid
        else l:= mid+1;
    end;
    s1:= abs(b[l]-x);
    l:= 1;
    r:=m;
    while l<r do
    begin
        mid:= (l+r+1) div 2;
        if b[mid]<=x then l:= mid
        else r:= mid-1;
    end;
    s2:= abs(x-b[l]);
    exit(min(s1,s2));
end;
procedure main;
begin
    kq:= 0;
    for i:= 1 to n do
        kq:= max(kq,nearest(a[i]));
end;
begin
    start;
    main;
    writeln(fo,kq);
    close(fi); close(fo);
end.