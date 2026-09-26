Program xephang;
var n:byte;
    k:integer;
procedure doicho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure xuly;
var fi,fo:text;
    i,j:byte;
    a:array[1..100] of integer;
begin
  assign(fi,'Xephang.inp');reset(fi);
  assign(fo,'Xephang.out');rewrite(fo);
  readln(fi,n,k);
  for i:=1 to n do
    read(fi,a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        doicho(a[i],a[j]);
  i:=1;
  while (a[i]<k) and (i<=n) do
    inc(i);
  for j:=n downto i do
    a[j+1]:=a[j];
  a[i]:=k;
  inc(n);
  writeln(fo,i);
  for i:=1 to n do
    write(fo,a[i],' ');
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

