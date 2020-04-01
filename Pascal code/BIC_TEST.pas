uses crt;
var fo:text;
	n,m,u,v,i:longint;
begin
        randomize;
	assign(fo,'C:\Users\admin\Google Drive\TEST\TEST05\BIC.INP'); rewrite(fo);
	n:=random(20);
	m:=random(30);
	writeln(fo,n,' ',m);
	for i:= 1 to m do
	begin
		repeat
			u:= random(n)+1;
			v:= random(n)+1;
		until u<>v;
		writeln(fo,u,' ',v);
	end;
	close(fo);
end.
