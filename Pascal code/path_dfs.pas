//dfs
const max=100;
var a:array[1..max,1..max] of shortint;
    tr: array[1..max] of longint;
    n,m,s,f,i:longint;
procedure input;
var fi:text;
    u,v: longint;
begin
    assign(fi,'path.inp'); reset(fi);
    readln(fi,n,m,s,f);
    fillchar(a,sizeof(a),0);
    fillchar(tr,sizeof(tr),0); tr[s]:= -1;
    for i:=1 to m do
    begin
        readln(fi,u,v);
        a[u,v]:= 1;
        a[v,u]:= 1;
    end;
    close(fi);
end;
procedure dfs(u:longint);
var i:longint;
begin
    for i:= 1 to n do
        if (tr[i]=0) and (a[u,i]=1) then
        begin
            tr[i]:= u;
            dfs(i);
        end;
end;
procedure output;
var vt:longint;
begin
    writeln('Possible destinations: ');
    for i:=1 to n do if tr[i]<>0 then write(i,' ');
    writeln;
    write('Path from ',s,' to ',f,': ');
    if tr[f]>0 then
    begin
        vt:= f;
    repeat
        write(vt,'<-');
        vt:=tr[vt];
    until vt=s;
    end;
    write(s);
    readln;
end;
begin
    input;
    dfs(s);
    output;
end.
