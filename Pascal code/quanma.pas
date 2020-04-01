type cell=record
    x:longint; y:longint; end;
var fi,fo:text;
    q:array[0..1000001] of cell;
    free:array[-2..1003,-2..1003] of boolean;
    n,m,i,j,count,head,foot,loop,long:longint;
    s,f,tmp:cell;
    dx:array[1..8] of shortint = (-2,-2,-1,-1,1,1,2,2);
    dy:array[1..8] of shortint = (-1,1,-2,2,-2,2,-1,1);
procedure start;
begin
    readln(n,m);
    readln(s.x,s.y);
    readln(f.x,f.y);
end;
procedure push(a,b:longint);
begin
    inc(foot);
    q[foot].x:= a;
    q[foot].y:= b;
    free[a,b]:= false;
end;
function pop():cell;
begin
    inc(head);
    exit(q[head-1]);
end;
procedure main;
begin
    for i:= -2 to n+2 do
    for j:= -2 to m+2 do free[i,j]:= not((i<1) or (i>n) or (j<1) or (j>m));
    head:=1; foot:= 0; push(s.x,s.y);
    count:= 0;
    repeat
        inc(count);
        long:= foot-head+1;
        for loop:= 1 to long do
        begin
            tmp:= pop;
            for i:= 1 to 8 do
            if free[tmp.x+dx[i],tmp.y+dy[i]] then
            begin
                push(tmp.x+dx[i],tmp.y+dy[i]);
                if (tmp.x+dx[i]=f.x) and (tmp.y+dy[i]=f.y) then exit;
            end;
        end;
    until head>foot;
end;
begin
    start;
    main;
    if free[f.x,f.y]=false then writeln(count)
    else writeln(-1);
end.