const fin='electric.inp'; fon='electric.out';
type edge=record
    u:longint;
    v:longint;
    c:longint;
    o:longint;
    end;
var pre,chon:array[0..100003] of longint;
    e:array[0..200003] of edge;
    n,m,i,count,s:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to m do
    with e[i] do readln(fi,u,v,c);
    for i:= 1 to m do e[i].o:= i;
end;
procedure sort1(l,r:longint);
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
    if l<j then sort1(l,j);
    if i<r then sort1(i,r);
end;
procedure sort2(l,r:longint);
var i,j,mid:longint;
    tmp: longint;
begin
    i:= l; j:= r; mid:= chon[(l+r) div 2];
    repeat
        while chon[i]<mid do inc(i);
        while chon[j]>mid do dec(j);
        if i<=j then
        begin
            tmp:= chon[i]; chon[i]:=chon[j]; chon[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
end;
function root(u:longint):longint;
begin
    while pre[u]>0 do u:= pre[u];
    exit(u);
end;
procedure union(u,v,c,o:longint);
var ru,rv:longint;
begin
    ru:= root(u); rv:= root(v);
    if ru<>rv then
    begin
        s:=s+c;
        inc(count);
        chon[count]:= o;
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
    count:= 0; s:= 0;
    for i:= 1 to n do pre[i]:= -1;
    for i:= m downto 1 do
    begin
        with e[i] do union(u,v,c,o);
        if count=n-1 then exit;
    end;
end;
procedure finish;
begin
    writeln(fo,s);
    for i:= 1 to count do writeln(fo,chon[i]);
    close(fi); close(fo);
end;
begin
    start;
    sort1(1,m);
    kruskal;
    sort2(1,count);
    finish;
end.