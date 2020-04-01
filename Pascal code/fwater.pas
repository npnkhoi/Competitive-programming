uses math;
const fin=''; fon='';
type bang=record
    u:longint;
    v:longint;
    c:longint;
    end;
var n,m,i,j,x,w,count,ru,rv:longint;
    s:int64;
    fi,fo:text;
    root:array[0..303] of longint;
    e:array[0..303] of bang;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    m:= 0;
    for m:= 1 to n do
    begin
        readln(fi,w);
        e[m].u:= 0;
        e[m].v:= m;
        e[m].c:= w;
    end;
    for i:= 1 to n do
    begin
        for j:= 1 to n do
        read(fi,p[i,j]);
    end;
    for i:= 1 to n do
    for j:= 1 to n do
    if i<j then
    begin
        inc(m);
        with e[m] do u:=i; v:= j; c:= p[i,j];
    end;
end;
procedure finish;
begin
    writeln(fo,s);
    close(fi); close(fo);
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
    tmp:bang;
begin
    i:= l; j:= r;
    mid:= e[(l+r) div 2].c;
    repeat
    while e[i].c<mid do inc(i);
    while e[j].c>mid do dec(j);
    if i<=j then
    begin
        tmp:= e[i];
        e[i]:= e[j];
        e[j]:= tmp;
        inc(i);
        dec(j);
    end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;

function findroot(u:longint):longint;
begin
    while root[u]<>u do u:= root[u];
    exit(u);
end;

procedure union(u,v,c:longint);
begin
    u:= findroot(u); v:=findroot(v);
    if u<>v then
    begin
    root[u]:=v;
    inc(count); inc(s,c);
    end;
end;

procedure main;
begin
    for i:= 0 to n do root[i]:= i;
	count:= 0; s:= 0;
    for i:= 1 to m do
    begin
        with e[i] do union(u,v,c);
    end;
end;

begin
    start;
    sort(1,m);
    main;
    finish;
end.
