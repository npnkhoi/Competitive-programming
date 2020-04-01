uses math;
type arr=array[0..1001] of longint;
const maxc=100001;
var n,m,a,b,k,i,j,u,v,min0,loop,tg:longint;
    da,db:array[0..1001] of longint;
    c:array[0..1001,0..1001] of longint;
    free:array[0..1001] of boolean;
    ok:boolean;
    fi,fo:text;
procedure start;
begin
    assign(fi,'warranty.inp'); reset(fi);
    assign(fo,'warranty.out'); rewrite(fo);
    readln(fi,n,m,a,b,k);
    for i:= 1 to n do
    for j:= 1 to n do c[i,j]:= maxc;
    for i:= 1 to m do
    begin
        read(fi,u,v);
        readln(fi,c[u,v]);
        c[v,u]:= c[u,v];
    end;
end;
procedure dijsktra(var d:arr;s:longint);
var i:longint;
begin
    for i:= 1 to n do d[i]:= maxc;
    for i:= 1 to n do free[i]:= true;
    d[s]:= 0;
    for loop:= 1 to n do
    begin
        min0:= maxc;
        for i:= 1 to n do if (free[i]) and (d[i]<min0) then
        begin
            min0:= d[i];
            tg:= i;
        end;
        free[tg]:= false;
        for i:= 1 to n do d[i]:=min(d[tg]+c[tg,i],d[i]);
    end;
end;
begin
    start;
    dijsktra(da,a);
    dijsktra(db,b);
    ok:= true;
    for i:= 1 to n do if (da[i]>k) and (db[i]>k) then begin write(fo,i,' '); ok:= false; end;
    if ok then write(fo,-1);
    close(fi); close(fo);
end.