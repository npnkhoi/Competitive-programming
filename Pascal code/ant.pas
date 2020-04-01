uses crt;
const fin='ant.inp'; fon='ant.out';
type bang=record
        x:longint;
        y:longint;
        end;
var fi,fo:text;
    c,s,x0,y0,i,j,k,head,foot,count:longint;
    queue:array[0..4005000] of bang;
    dx:array[1..4] of -1..1 = (-1,1,0,0);
    dy:array[1..4] of -1..1 = (0,0,-1,1);
    tmp:bang;
    map:array[-1001..1001,-1001..1001] of -1..1;
procedure inbang;
var i,j:longint;
begin
for i:= -s to s do
    begin
    for j:= -s to s do write(map[i,j]:3);
    writeln;
    end;
    readln;
end;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,c,s);
    fillchar(map,sizeof(map),0);
    for i:= 1 to c do
    begin
        readln(fi,x0,y0);
        map[x0,y0]:= -1;
    end;
    //inbang;
end;
procedure push(a,b:longint);
begin
    inc(foot);
    queue[foot].x:=a;
    queue[foot].y:=b;
end;
procedure pop;
begin
    tmp.x:= queue[head].x;
    tmp.y:= queue[head].y;
    inc(head);
end;

procedure main;
begin
    head:= 1; foot:= 0;
    push(0,0); map[0,0]:= 1;
    for i:= 1 to s do
    begin
        count:= foot-head+1;
        for j:= 1 to count do
        begin
            pop;
            for k:= 1 to 4 do if map[tmp.x+dx[k],tmp.y+dy[k]]=0 then
            begin
                map[tmp.x+dx[k],tmp.y+dy[k]]:= 1;
                push(tmp.x+dx[k],tmp.y+dy[k])
            end;
        end;
        //inbang;
    end;
end;
begin
    start;
    main;
    writeln(fo,foot);
    close(fi); close(fo);
end.
