uses math;
const fi='warranty.inp';
fo='warranty.out'; maxc=1000;
type mang=array[1..1003]of longint;
var c:array[1..1003,1..1003]of longint;
m,n,k,i,j,s,a,b,u,v,dem:longint;
f:text;
d,trace,da,db:array[1..1003]of longint;
free:array[1..1003]of boolean;
procedure dt(var d:mang;s:longint);
var i,u,v:longint;
min:longint;
begin
     for i:=1 to n do d[i]:=maxc;
     d[s]:=0;
     fillchar(free,sizeof(free),true);
     repeat
           u:=0;min:=maxc;
           for i:=1 to n do
           if free[i]and (d[i]<min)then
           begin
                min:=d[i];
                u:=i;
           end;
           if (u=0) or (u=a)or(u=b) then break;
           free[u]:=false;
           for v:=1 to n do
            if (free[u])and(d[v]>d[u]+c[u,v])then
            begin
                d[v]:=d[u]+c[u,v];
                trace[v]:=u;
            end;
     until false;
end;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,a,b,k);
        for u:=1 to n do
        for v:=1 to n do if u=v then c[u,v]:=0 else c[u,v]:=maxc;
        for i:=1 to m do
                begin
                        readln(f,u,v,c[u,v]);
                        c[v,u]:=c[u,v];
                end;
        dem:=0;
        close(f);
        assign(f,fo);
        rewrite(f);
        dt(da,a);
        dt(db,b);
        for i:=1 to n do
                begin
                     s:=i;
                     if (min(da[i],db[i])<=k)then
                        begin
                                write(f,i,' ');
                                dem:=dem+1;
                        end;
                end;
        if dem=0 then write(f,'-1');
        close(f);
end.
