uses math;
Const
 Fi='dayso.inp';
 Fo='';
 MaxN=trunc(5e5)+5;
Var
 F,G : text;
 res:int64;
 n:longint;
 a,b,p,pre,next:array[0..maxN] of longint;

Procedure nhap;
Var i: longint;
Begin
 assign(F,Fi);reset(F);
 readln(F,n);
 for i:=1 to n do
 begin
  read(f,a[i]);b[i]:=a[i];p[i]:=i;
 end;
 close(F);
end;
Procedure swap(var a,b : longint);
Var y : longint;
Begin
 y:=a; a:=b; b:=y;
end;

Procedure qsort(l,r:longint);
Var i,j,x,y : longint;
Begin
 if l>=r then exit;
 i:=l; j:=r; x:=a[l+random(r-l+1)];
 Repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then
  Begin
   swap(a[i],a[j]);
   swap(p[i],p[j]);
   inc(i);dec(j);
  end;
 until i>j;
 qsort(l,j);
 qsort(i,r);
end;
Procedure xuly;
Var i,j,x,y,l,r : longint;
Begin
 for i:=1 to n do
  begin
   pre[i]:=i-1; next[i]:=i+1;
  end;
  l:=1; r:=n; qsort(1,n);
  for i:=1 to n-2 do
  begin
  if p[i]=l then
  Begin
   res :=res + a[i];
   l:=next[p[i]];
  end
  else if p[i]=r then
  Begin
   res:=res+a[i];
   r:=pre[p[i]];
  end
  else
   begin
    y:=next[p[i]];x:=pre[p[i]];
    next[x]:=y;pre[y]:=x;
    res:=res+min(b[x],b[y]);
   end;
   writeln(res);
end;
end;
Procedure xuat;
Begin
 assign(G,Fo);
 rewrite(G);
 write(G,res);
 close(G);
end;
Begin
 nhap;
 xuly;
 xuat;
end.




