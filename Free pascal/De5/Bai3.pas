Program bai3;
var s:string;
function Ho(s:string):string;
var i:byte;
begin
  i:=pos(#32,s);
  delete(s,i,length(s)-i+1);
  Ho:=s;
end;
function Ten(s:string):string;
var i:byte;
begin
  i:=length(s);
  while s[i]<>#32 do
    dec(i);
  delete(s,1,i);
  Ten:=s;
end;
procedure xuly;
var fi,fo:text;
    i:byte;
    ch:set of char;
    kq:string;
begin
  assign(fi,'HovaTen.inp');reset(fi);
  assign(fo,'HovaTen.out');rewrite(fo);
  read(fi,s);
  writeln(fo,'Ho: ',Ho(s));
  writeln(fo,'Ten: ',Ten(s));
  ch:=[];
  kq:='';
  for i:=1 to length(s) do
    if (not(s[i] in ch)) or (s[i]=#32) then
      begin
        ch:=[s[i]]+ch;
        kq:=kq+s[i];
      end;
  write(fo,kq);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
