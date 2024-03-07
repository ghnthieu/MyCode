Program tron_mang;
uses crt;
type mangab=array[1..100] of integer;
     mangc=array[1..200] of integer;
var a,b:mangab;
    n,m:byte;
procedure nhap(var a,b:mangab; var m,n:byte);
var i:byte;
begin
  write('Nhap so phan tu mang A: ');readln(m);
  for i:=1 to m do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
  write('Nhap so phan tu mang B: ');readln(n);
  for i:=1 to n do
    begin
      write('b[',i,']=');readln(b[i]);
    end;
  writeln('Mang theo thu tu giam la: ');
end;
procedure doi_cho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure sx_giam(var a:mangab; m:byte);
var i,j:byte;
begin
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if a[i]<a[j] then
        doi_cho(a[i],a[j]);
  for i:=1 to m do
    write(a[i],' ');
  writeln;
end;
procedure gop_giam(a,b:mangab; m,n:byte);
var i,j,k:byte;
    c:mangc;
begin
  i:=1;
  j:=1;
  k:=1;
  while (i<=m) and (j<=n) do
    if a[i]>b[j] then
      begin
        c[k]:=a[i];
        inc(i);
        inc(k);
      end
    else
      begin
        c[k]:=b[j];
        inc(j);
        inc(k);
      end;
  if i>m then
    while j<=n do
      begin
        c[k]:=b[j];
        inc(j);
        inc(k);
      end
  else
    while i<=m do
      begin
        c[k]:=a[i];
        inc(i);
        inc(k);
      end;
  dec(k);
  for i:=1 to k do
    write(c[i],' ');
  writeln;
  writeln('Mang theo thu tu tang la: ');
end;
procedure sx_tang(var a:mangab; m:byte);
var i,j:byte;
begin
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if a[i]>a[j] then
        doi_cho(a[i],a[j]);
  for i:=1 to m do
    write(a[i],' '); 
  writeln;
end;
procedure gop_tang(a,b:mangab; m,n:byte);
var i,j,k:byte;
    c:mangc;
begin
  i:=1;
  j:=1;
  k:=1; 
  while (i<=m) and (j<=n) do
    if a[i]<b[j] then
      begin
        c[k]:=a[i];
        inc(i);
        inc(k);
      end
    else
      begin
        c[k]:=b[j];
        inc(j);
        inc(k);
      end;
  if i>m then
    while j<=n do
      begin
        c[k]:=b[j];
        inc(j);
        inc(k);
      end
  else
    while i<=m do
      begin
        c[k]:=a[i];
        inc(i);
        inc(k);
      end;
  dec(k);
  for i:=1 to k do
    write(c[i],' ');
end;

Begin
  clrscr;
  nhap(a,b,m,n);
  sx_giam(a,m);
  sx_giam(b,n);
  gop_giam(a,b,m,n);
  sx_tang(a,m);
  sx_tang(b,n);
  gop_tang(a,b,m,n);
  readln
End.