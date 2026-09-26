Program bai4;
var n:byte;
    s:string;
function Ten(s:string):string;
var i:byte;
begin
  i:=length(s);
  while s[i]<>#32 do
    dec(i);
  delete(s,1,i);
  Ten:=s;
end;
function Sok(s:string):string;
begin
  Sok:=s[1];
end;
function Ho(s:string):string;
var i:byte;
begin
  i:=pos(Ten(s),s);
  delete(s,i-1,length(Ten(s))+1);
  delete(s,1,length(Sok(s))+1);
  Ho:=s;
end;
function doicho(var a,b:string):string;
var t:string;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure xuly;
var i,j:byte;
    fi,fo:text;
    ht:array[1..200] of string;
begin
  assign(fi,'C:\Code\Free pascal\De8\\BAI4.INP');reset(fi);
  assign(fo,'C:\Code\Free pascal\De8\\BAI4.OUT');rewrite(fo);
  readln(fi,n);
  for i:=1 to n do
    readln(fi,ht[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if Sok(ht[i])>Sok(ht[j]) then
          doicho(ht[i],ht[j])
        else
          if Sok(ht[i])=Sok(ht[j]) then
            if Ten(ht[i])>Ten(ht[j]) then
              doicho(ht[i],ht[j])
            else
              if Ten(ht[i])=Ten(ht[j]) then
                if Ho(ht[i])>Ho(ht[j]) then
                  doicho(ht[i],ht[j]);
      end;
  for i:=1 to n do
    writeln(fo,ht[i]);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

