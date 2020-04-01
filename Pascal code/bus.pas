var fi,fo:text;
    t,a,head:array[0..200003] of longint;
    n,m,i,j,time,k,l,r,mid:longint;
procedure start;
begin
    assign(fi,''); reset(fi);
    assign(fo,''); rewrite(fo);
    readln(fi,n,m);
    head[1]:= 0; t[1]:= 0;
    for i:= 1 to n do
    begin
        read(fi,time,k);
        t[i+1]:= t[i]+time;
        head[i+1]:= head[i]+k;
        for j:= 1 to k do read(fi,a[head[i]+j]);
    end;
end;
function songuoi(x:longint):int64;
var i:longint;
    s:int64;
begin
    s:= 0;
    for i:= 1 to n do
    for j:= head[i]+1 to head[i+1] do
    if t[i]+x>=a[j] then inc(s);
    exit(s);
end;
procedure main;
begin
    l:= 0;
    r:= 2147483647-t[n+1];
    while l<r do
    begin
        mid:= (l+r) div 2;
        if songuoi(mid)>=m then r:= mid
        else l:= mid+1;
    end;
end;
begin
    start;
    main;
    writeln(fo,t[n+1]+l);
    close(fi); close(fo);
end.