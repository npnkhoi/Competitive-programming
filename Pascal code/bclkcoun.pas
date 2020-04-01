
//uses crt,math;
const
        fin=''; fon='';
var m,n,i,j,count:longint;
    fi,fo:text;
    o:array[0..103] of string;
    dy:array [1..8] of shortint=(-1,-1,-1,0,0,1,1,1);
    dx:array [1..8] of shortint=(-1,0,1,-1,1,-1,0,1);
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,m,n);
    for i:= 1 to m do
        readln(fi,o[i]);
end;
procedure inbang;
var i,j:longint;
begin
    for i:= 1 to m do
    begin
    for j:= 1 to n do write(o[i][j]);
    writeln;
    end;
    writeln;
end;
procedure visit(x,y:longint);
var i:longint;
begin
    o[x][y]:= '.';
    //inbang;
    for i:= 1 to 8 do
    if o[x+dx[i]][y+dy[i]]='W' then visit(x+dx[i],y+dy[i]);
end;
procedure main;
begin
    count:= 0;
    for i:= 1 to m do
    for j:= 1 to n do
    if o[i][j]='W' then
    begin
        inc(count);
        visit(i,j);
    end;
end;
procedure finish;
begin
    writeln(fo,count);
    close(fi); close(fo);
end;
begin
    start;
    main;
    finish;
end.
