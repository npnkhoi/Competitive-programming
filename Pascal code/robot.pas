uses crt;
const fin='robot.inp';
    fon='robot.out';
var fi,fo:text;
    n,i,j:integer;
    a:array[1..51,1..51] of byte;
    min:array[0..51,0..51] of string;
procedure load;
begin
    assign(fi,fin); reset(fi);
    readln(fi,n);
    for i:=1 to n do
    for j:= 1 to n do read(fi,a[i,j]);
    close(fi);
end;

procedure dp;
var x:char;
begin
    //init
    min[1,1]:= chr(a[1,1]+48);
    for i:= 2 to n do
        begin
            min[1,i]:= min[1,i-1]+chr(a[1,i]+48);
            min[i,1]:= min[i-1,1]+chr(a[i,1]+48);
        end;
    /////////////////////////////
    for i:= 2 to n do
    for j:= 2 to n do
        begin
            x:= chr(a[i,j]+48);
        if min[i,j-1]<min[i-1,j] then
            min[i,j]:= min[i,j-1]+x
            else min[i,j]:= min[i-1,j]+x;
        //writeln(i,' ',j,' ',min[i,j]); readln;
        end;
end;

procedure output;
begin
        assign(fo,fon); rewrite(fo);
    writeln(fo,min[n,n]);
    close(fo);
end;

begin
    load;
    dp;
    output;
end.