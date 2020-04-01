uses math,crt;
type rc=record
    u:longint;
    v:longint;
    c:longint;
    end;
var n,m,s,t,i,j,u,v:longint;
    pre:array[0..1001] of longint;
    e:array[0..10001] of rc;
procedure start;
begin
    readln(n,m,s,t);
    for i:= 1 to m do
    begin
        with e[i] do readln(u,v,c);
    end;
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
    tmp:rc;
begin
    i:= l; j:= r; mid:= e[(l+r) div 2].c;
    repeat
        while e[i].c<mid do inc(i);
        while e[j].c>mid do dec(j);
        if i<=j then
        begin
            tmp:= e[i]; e[i]:= e[j]; e[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;
function root(u:longint):longint;
begin
    while pre[u]>0 do u:= pre[u];
    exit(u);
end;
procedure union(u,v:longint);
var a,b:longint;
begin
    a:= root(u); b:= root(v);
    if a<>b then
    begin
        if pre[a]<pre[b] then
        begin
            inc(pre[a],pre[b]);
            pre[b]:= a;
        end
            else
        begin
            inc(pre[b],pre[a]);
            pre[a]:= b;
        end;
    end;
end;
procedure main;
begin
    sort(1,m);
    for i:=  1 to n do pre[i]:= -1;
    for i:= m downto 1 do
    begin
        with e[i] do union(u,v);
        if root(s)=root(t) then exit;
    end;
end;
begin
    start;
    main;
    if root(s)=root(t) then write(e[i].c)
    else write(-1);
end.