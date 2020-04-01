uses math;
const fin=''; fon='';
type edge=record
    u:longint;
    v:longint;
    c:longint;
    end;
var pre:array[0..1003] of longint;
    e:array[0..10003] of edge;
    n,m,i,count,s:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to m do
    with e[i] do
        readln(fi,u,v,c);
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
    tmp: edge;
begin
    i:= l; j:= r; mid:= e[(l+r)div 2].c;
    repeat
        while e[i].c<mid do inc(i);
        while e[j].c>mid do dec(j);
        if i<=j then
        begin
            tmp:= e[i]; e[i]:= e[j]; e[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;

function root(u:longint):longint;
begin
    while pre[u]>0 do u:= pre[u];
    exit(u);
end;
procedure union(u,v,c:longint);
var ru,rv:longint;
begin
    ru:= root(u); rv:= root(v);
    if ru<>rv then
    begin
        s:= max(s,c);
        inc(count);
        if pre[ru]<pre[rv] then
        begin
            inc(pre[ru],pre[rv]);
            pre[rv]:= u;
        end
            else
        begin
            inc(pre[rv],pre[ru]);
            pre[ru]:= v;
        end;
    end;
end;
procedure kruskal;
begin
    count:= 0; s:=e[1].c;
    for i:= 1 to n do pre[i]:= -1;
    for i:= 1 to m do
    begin
        with e[i] do union(u,v,c);
        if count=n-1 then exit;
    end;
end;
procedure finish;
begin
    writeln(fo,s);
    close(fi); close(fo);
end;
begin
    start;
    sort(1,m);
    kruskal;
    finish;
end.
