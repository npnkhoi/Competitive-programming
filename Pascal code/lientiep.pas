uses math;
var fi,fo:text;
    n,m,loop,i,j,l,r,d,tmp,kq:longint;
    ask:char;  st:string;
    a,s:array[0..100001] of longint;
function head(var st:string):longint;
var e,x:integer;
    so:longint;
begin
    x:= pos(' ',st);
    if x=0 then
    begin
        val(st,so,e);
        x:= length(st);
    end
        else val(copy(st,1,x-1),so,e);
    delete(st,1,x);
    exit(so);
end;
begin
    assign(fi,'lientiep.inp'); reset(fi);
    assign(fo,''); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do read(fi,a[i]);
    for i:= 1 to n-1 do s[i]:= a[i+1]-a[i];
    readln(fi,m);
    for loop:=  1 to m do
    begin
        readln(fi,st);
        ask:= st[1];
        delete(st,1,2);
        if ask='+' then
        begin
            l:= head(st);
            r:= head(st);
            d:= head(st);
            inc(s[l-1],d);
            dec(s[r],d);
        end
            else
        begin
            l:= head(st);
            r:= head(st);
            tmp:= 0; kq:= 0;
            for i:= l to r-1 do
            if s[i]=1 then
            begin
                inc(tmp);
                kq:= max(kq,tmp);
            end
                else tmp:= 0;
            inc(kq);
            writeln(fo,kq);
        end;
    end;
    close(fi); close(fo);
end.
