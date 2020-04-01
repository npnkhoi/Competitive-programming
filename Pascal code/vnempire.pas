
type
    bang=record
        u:longint;
        v:longint;
        c:int64;
        end;
    arr1=array[0..100003] of int64;
    arr2=array[0..300003] of bang;
const fin=''; fon='';
var pre:arr1;
    x,y,z,e:arr2;
    n,i,j,m,count:longint;
    s:int64;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do
    begin
        readln(fi,x[i].c,y[i].c,z[i].c);
        x[i].u:= i;
        y[i].u:= i;
        z[i].u:= i;
    end;
end;
procedure sort2(var a:arr2; l,r:longint);
var i,j,mid:longint;
    tmp: bang;
begin
    i:= l; j:= r; mid:= a[(l+r)div 2].c;
    repeat
        while a[i].c<mid do inc(i);
        while a[j].c>mid do dec(j);
        if i<=j then
        begin
            tmp:= a[i]; a[i]:= a[j]; a[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort2(a,l,j);
    if i<r then sort2(a,i,r);
end;

procedure build;
begin
    sort2(x,1,n);
    sort2(y,1,n);
    sort2(z,1,n);
    for i:= 1 to n-1 do
    begin
        e[i].c:= abs(x[i+1].c-x[i].c);
        e[i].u:= x[i].u;
        e[i].v:= x[i+1].u;
    end;
    for i:= 1 to n-1 do
    begin
        e[n-1+i].c:= abs(y[i+1].c-y[i].c);
        e[n-1+i].u:= y[i].u;
        e[n-1+i].v:= y[i+1].u;
    end;
    for i:= 1 to n-1 do
    begin
        e[2*n-2+i].c:= abs(z[i+1].c-z[i].c);
        e[2*n-2+i].u:= z[i].u;
        e[2*n-2+i].v:= z[i+1].u;
    end;
    m:= 3*n-3;
    sort2(e,1,m);
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
procedure main;
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
    build;
    main;
    finish;
end.
