procedure load_matrix_edge_value;
var u,v,k:longint;
begin
    assign(fi,fin); reset(fi);
    readln(fi,n,m,s,f);
    ///////////////////////////////////////////
    for i:= 1 to n do
    for j:= 1 to n do
         if i=j then c[i,j]:= 0 else c[i,j]:= maxint;
    for i:= 1 to m do
    begin
        read(fi,u,v,k);
        c[u,v]:= k;
    end;
end;

procedure load_edgematrix_nonvalue;
var u,z,k:longint;
begin
    assign(fi,fin); reset(fi);
    readln(fi,n,m,s,f);
    ///////////////////////////////////////////
    fillchar(c,sizeof(c),0);
    for i:= 1 to m do
    begin
        read(fi,u,v);
        c[u,v]:= 1;
    end;
end;

procedure dijsktra;
var loop:longint;
    finish:boolean;
begin
    for loop:= 1 to n-1 do
    begin
        finish:= true;
        for i:= 1 to n do
        for j:= 1 to n do
        if d[j]>d[i]+c[i,j] then
            begin
                d[j]:=d[i]+c[i,j];
                trace[j]:=i;
                finish:= false;
            end;
        if finish then break;
    end;
end;

procedure ford_bellman;
var loop:longint;
    finish:boolean;
begin
    for loop:= 1 to n-1 do
    begin
        finish:= true;
        for i:= 1 to n do
        for j:= 1 to n do
        if d[j]>d[i]+c[i,j] then
            begin
                d[j]:=d[i]+c[i,j];
                trace[j]:=i;
                finish:= false;
            end;
        if finish then break;
    end;
end;
//---------------------------------------
const fin='basetree.inp'; fon='';
type edge=record
    u:longint;
    v:longint;
    c:longint;
    end;
var pre:array[0..10003] of longint;
    e:array[0..100003] of edge;
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
        inc(s,c);
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
