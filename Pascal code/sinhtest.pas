uses math;
const fin='';
	fon='average.inp';
    nmax= trunc(1e5);
    aimax=trunc(1e6);
var fi,fo:text;
    n,k,i:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
end;
procedure main;
begin
    n:= random(100);
    k:=random(n);
    writeln(fo,n,' ',k);
    for i:= 1 to n do
    write(fo,random(aimax),' ');
end;
procedure output;
begin
	close(fi); close(fo);
end;
begin
    randomize;
    input;
    main;
    output;
end.