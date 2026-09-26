Program Mang_uoc_snt;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap n: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure doicho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
function snt(n:longint):boolean;
var i:longint;
begin
  if (n<2) then
    exit(false);
  for i:=2 to trunc(sqrt(n)) do
    if (n mod i=0) then
      exit(false);
  exit(true);
end;
procedure xuly(a:mang; n:byte);
var i,j,cs,maxdem:byte;
    uoc:array[1..100] of longint;
    dem:array[1..32767] of byte;
    max,tong:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i]<a[j]) then
        doicho(a[i],a[j]);
  write('Mang theo thu tu giam dan la: ');
  fillchar(dem,sizeof(dem),0);
  for i:=1 to n do
    begin
      write(a[i],' ');
      inc(dem[a[i]]);
    end;
  writeln;
  writeln('Uoc cua cac phan tu la: ');
  max:=0;
  for i:=1 to n do
    begin
      tong:=a[i];
      write(a[i],' : ');
      for j:=1 to a[i] div 2 do
        if (a[i] mod j=0) then
          begin
            tong:=tong+j;
            write(j,' ');
          end;
      write(a[i]);
      uoc[i]:=tong;
      if (tong>max) then
        max:=tong;
      writeln;
    end;
  write('Cac phan tu co tong uoc lon nhat la: ');
  for i:=1 to n do
    if (uoc[i]=max) then
      write(uoc[i],' ');
  writeln;
  write('Cac tong la so nguyen to la: ');
  for i:=1 to n do
    if (snt(uoc[i])) then
      write(uoc[i],' ');
  writeln;
  maxdem:=0;
  for i:=1 to a[1] do
    if (dem[i]>maxdem) then
      begin
        maxdem:=dem[i];
        cs:=i;
      end;
  write('so phan tu bang nhau nhieu nhat la: ','a[i]=',cs,' co ',maxdem,' phan tu');
end;
Begin
  clrscr;
  nhap(a,n);
  xuly(a,n);
  readln
End.


