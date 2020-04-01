uses math,crt;
type bang=record
    r:byte;
    c:byte;
    end;
const fin='mtngto.inp';
	fon='';
var fi,fo:text;
    a:array[1..15,1..15] of byte;
    hang,cot:array[1..15,1..60] of boolean;
    emp:array[1..300] of bang;
    ngto:array[1..15] of integer;
    n,i,j,count,x:integer;
procedure output;
begin
	close(fi); close(fo);
end;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do
    for j:= 1 to n do
    begin
        read(fi,a[i,j]);
        if a[i,j]=0 then
        begin
            inc(count);
            emp[count].r:= i;
            emp[count].c:= j;
        end;
    end;
end;
function ktnt(x:integer):boolean;
var i: integer;
begin
    for i:= 2 to trunc(sqrt(x)) do if x mod i = 0 then exit(false);
    exit(true);
end;
procedure init;
begin
    fillchar(hang,sizeof(hang),true);
    fillchar(cot,sizeof(cot),true);
    for i:= 1 to n do
    for j:= 1 to n do
    if a[i,j]<>0 then
    begin
        hang[i,a[i,j]]:= false;
        cot[j,a[i,j]]:= false;
    end;
    x:= 1;
    for i:= 1 to n do
    begin
        repeat inc(x) until ktnt(x);
        ngto[i]:= x;
    end;
end;
procedure thongbao;
var i,j:integer;
begin
    for i:=1 to n do
    begin
        for j:= 1 to n do
        write(fo,a[i,j]:3);
        writeln(fo);

    end;
    writeln;
end;
procedure try(i:longint);
var j:integer;
begin
    for j:= 1 to n do
        if(hang[emp[i].r,ngto[j]]) and (cot[emp[i].c,ngto[j]]) then
    begin
        a[emp[i].r,emp[i].c]:= ngto[j];
        hang[emp[i].r,ngto[j]]:= false;
        cot[emp[i].c,ngto[j]]:= false;
        if i=count then thongbao else try(i+1);
        hang[emp[i].r,ngto[j]]:= true;
        cot[emp[i].c,ngto[j]]:= true;
    end;
end;
begin
        clrscr;
    input;
    init;
    try(1);
    output;
end.