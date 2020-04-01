uses math;
const fin='';
    fon='';
	nmax=trunc(1e5)+7;
var fi,fo:text;
	n:ansistring;
	k,l,i,mark,duong:longint;
procedure input;
begin
	assign(fi,fin); reset(fi);
	assign(fo,fon); rewrite(fo);
	readln(fi,l,k);
	readln(fi,n);
end;
function cl(vt:longint):longint;
begin
	exit(ord(n[vt+1])-ord(n[vt]));
end;

procedure main;
begin
	mark:= 1;
	for i:= 1 to k do
	begin
        if mark<l-i+1 then
		begin
            while (mark<l-i+1) and (cl(mark)<=0) do inc(mark);
	        if mark<l-i+1 then
		    begin
		        delete(n,mark,1);
		        if (mark>1) and (cl(mark-1)>0) then dec(mark);
			end
				else
			begin
				delete(n,length(n)+i-k,k-i+1);
				break;
			end
		end
		else
			begin
				delete(n,l+i-k,k-i+1);
				break;
			end;
	end;
end;
procedure output;
begin
	writeln(fo,n);
	close(fi); close(fo);
end;
begin
	input;
	main;
	output;
end.
