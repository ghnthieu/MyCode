Program bai1;
uses crt;
var n:integer;
procedure nhap(var n:integer);
begin
  repeat
    write('-Nhap n: ');readln(n);
  until (n>0) and (n<10000);
end;
function kt1(n:integer):boolean;
var ok:boolean;
    i:integer;
begin
  ok:=true;
  if n<2 then
    ok:=false
  else
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then
        begin
          ok:=false;
          break;
        end;
  kt1:=ok;
end;
function kt2(n:integer):boolean;
var ok:boolean;
    i,stn:integer;
begin
  stn:=0;
  for i:=1 to n div 2 do
    if n mod i=0 then
      stn:=stn+i;
  if stn=n then
    ok:=true
  else
    ok:=false;
  kt2:=ok;
end;
procedure xuly(n:integer);
var i:integer;
begin
  writeln('-Cac so nguyen to: ');
  for i:=1 to n-1 do
    if kt1(i) then
      write(i,' ');
  writeln;
  write('-Cac so hoan chinh: ');
  for i:=1 to n-1 do
    if kt2(i) then
      write(i,' ');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
