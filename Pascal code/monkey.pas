var fi,fo:text;
    m,n,i,l,r,mid,t:longint;
    a,b,c,d:array[0..101] of longint;
procedure start;
begin
    assign(fi,'monkey.inp'); reset(fi);
    assign(fo,'monkey.out'); rewrite(fo);
    readln(fi,t);
    readln(fi,n);
    for i:= 1 to n do readln(fi,a[i],b[i]);
    readln(fi,m);
    for i:= 1 to m do readln(fi,c[i],d[i]);
end;
function hai(x:longint):int64;
var s:int64;
    i:longint;
begin
    s:= 0;
    for i:= 1 to n do if x>=a[i] then inc(s,1+(x-a[i]) div b[i]);
	exit(s);
end;
function dap(x:longint):int64;
var s:int64;
    i:longint;
begin
    s:= 0;
    for i:= 1 to m do if x>=c[i] then inc(s,1+(x-c[i]) div d[i]);
    exit(s);
end;
procedure main;
begin
    l:= 1; r:= t;
    while l<r do
    begin
        mid:= (l+r+1) div 2;
        writeln(hai(mid),' ',dap(t-mid));
        if hai(mid)>dap(t-mid) then r:= mid-1
        else l:= mid;
    end;
end;
begin
    start;
    main;
    writeln(fo,l);
    close(fi); close(fo);
end.
