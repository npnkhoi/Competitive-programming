var fi,fo:text;
    n,m,i,l,r,mid:longint;
    a:array[0..300003] of longint;
procedure start;
begin
    assign(fi,'marble.inp'); reset(fi);
    assign(fo,'marble.out'); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to m do readln(fi,a[i]);
end;
function songuoi(x:longint):int64;
var i:longint;
    s:int64;
begin
    s:= 0;
    for i:= 1 to m do s:= s+(a[i]+x-1) div x;
end;
procedure main;
begin
    l:= 1;
    r:= 1000000000;
    while l<r do
    begin
        mid:= (l+r) div 2;
        if songuoi(mid)>n then l:= mid+1
        else r:= mid;
    end;
end;
begin
    start;
    main;
    writeln(fo,l);
    close(fi); close(fo);
end.