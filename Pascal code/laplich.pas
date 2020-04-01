uses crt;
type mang=array[1..1000] of integer;
var     n,m:longint;
        x,y: mang;
        i,j,dem:integer;
        f,g:text;

procedure swap(var z,h:integer);
var t:longint;
begin
        t:= z; z:=h; h:= t;
end;
procedure sorty(t,p:longint);
var i,j,xi:longint;
begin
        i:= t; j:= p;
        xi:= y[(t+p) div 2];
        repeat
                while (y[i]<xi) and (i<=j) do inc(i);
                while (y[j]>xi) and (i<=j) do dec(j);
                if i<=j then
                        begin
                                swap(y[i],y[j]);
                                inc(i); dec(j);
                        end;
        until i>j;
        if t<j then sorty(t,j);
        if i<p then sorty(i,p);
end;
procedure sortx(t,p:longint);
var i,j,xi:longint;
begin
        i:= t; j:= p;
        xi:= x[(t+p) div 2];
        repeat
                while (x[i]<xi) and (i<=j) do inc(i);
                while (x[j]>xi) and (i<=j) do dec(j);
                if i<=j then
                        begin
                                swap(x[i],x[j]);
                                inc(i); dec(j);
                        end;
        until i>j;
        if t<j then sortx(t,j);
        if i<p then sortx(i,p);
end;

begin
        assign(f,'laplich.inp');
        assign(g,'laplich.out');
        reset(f);rewrite(g);
        readln(f,n,m);
        for i:= 1 to n do read(f,x[i]);
        readln(f);
        for i:= 1 to m do read(f,y[i]);
        sortx(1,n);
        sorty(1,m);
        dem:= 0; j:= 1;
        for i:= 1 to m do
                if y[i]>x[j] then begin inc(dem); inc(j); end;
        writeln(g,dem);
        close(f); close(g);
end.