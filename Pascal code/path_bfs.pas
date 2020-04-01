const nmax=100;
    max=1000;
    vohuong=false;
var a:array[1..nmax,1..nmax] of shortint;
    tr: array[1..nmax] of longint;
    queue:array[1..max] of longint;
    n,m,s,f,i,wait,dau,cuoi,x:longint;
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
        if vohuong then a[v,u]:= 1;
    end;
    close(fi);
end;
////////////////////////////////////////
procedure init;
begin
    dau:= 1; cuoi:= 0;
    wait:= 0;
    fillchar(tr,sizeof(tr),0);
    fillchar(a,sizeof(a),0);
end;
////////////////////////////////////////
procedure push(x:longint);
begin
    if wait=max then begin write('Full!'); halt; end
    else
    begin
        inc(cuoi);
        inc(wait);
        queue[cuoi]:= x;
    end;
end;
procedure pop(var x:longint);
begin
    if wait=0 then begin write('Empty!'); halt; end
    else
    begin
        x:= queue[dau];
        inc(dau);
        dec(wait);
    end;
end;
////////////////////////////////////////
procedure bfs;
var i,j:longint;
begin
    push(s);
    repeat
            pop(x);
            for j:= 1 to n do
            if (tr[j]=0) and (a[x,j]=1) then
            begin
                push(j); tr[j]:= x;
            end;
    until wait<1;
end;
////////////////////////////////////////
procedure tim(x:longint);
begin
    if x=-1 then exit
    else
    begin
        tim(tr[x]);
        write(x,' ');
    end;
end;
procedure output;
var vt:longint;
begin
    writeln('Possible destinations: ');
    for i:=1 to n do if tr[i]<>0 then write(i,' ');
    writeln;
    write('Path from ',s,' to ',f,': ');
    if tr[f]>0 then tim(f)
    else writeln('There is no way to ',f);
    {if tr[f]>0 then
    begin
        vt:= f;
    repeat
        write(vt,'<-');
        vt:=tr[vt];
    until vt=s;
    end;
    write(s);
    readln;}
    readln;
end;
begin
    init;
    input;
    bfs;
    output;
end.
