uses math;
type bang=record
    u:longint;
    v:longint;
    c:longint;
    end;
const fin='D:\Themis\TEST\ELECTRIC\TEST03\electric.inp'; fon='';
    maxw=4000000;
var a,b:array[0..203] of bang;
    e:array[0..40003] of bang;
    pre:array[0..403] of longint;
    fi,fo:text;
    k,m,n,i,j,count,s:longint;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,k,n);
    for i:= 1 to k do
    with a[i] do readln(fi,u,v,c);
    for i:= 1 to n do
    with b[i] do readln(fi,u,v);
end;
function kc(p1,p2:bang):longint;
begin
    exit(abs(p1.u-p2.u)+abs(p1.v-p2.v));
end;
procedure build_edge;
begin
    for i:= 1 to n do
    begin
        e[i].u:= 0;
		e[i].v:= i;
        e[i].c:= maxw;
        for j:= 1 to k do e[i].c:=min(kc(a[j],b[i])+a[j].c,e[i].c);
    end;
    m:= n;
    for i:= 1 to n do
    for j:= 1 to n do
    if i<j then
    begin
        inc(m);
        e[m].u:= i;
        e[m].v:= j;
        e[m].c:= kc(b[i],b[j]);
    end;
end;
procedure sort(l,r:longint);
var i,j:longint;
    mid:longint;
    tmp: bang;
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
procedure union(u,v:longint;c:longint);
var ru,rv:longint;
begin
    ru:= root(u); rv:= root(v);
    if ru<>rv then
    begin
        s:=s+c;
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
    count:= 0; s:= 0;
    for i:= 0 to n do pre[i]:= -1;
    for i:= 1 to m do
    begin
        with e[i] do union(u,v,c);
        if count=n then exit;
    end;
end;
procedure finish;
begin
    writeln(fo,s);
    close(fi); close(fo);
end;
begin
    start;
    build_edge;
    sort(1,m);
    kruskal;
    finish;
end.
