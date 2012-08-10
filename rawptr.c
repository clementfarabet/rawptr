
#include <luaT.h>
#include <TH/TH.h>

static int Pointer_to_DoubleStorage(lua_State *L) {
  // get pointer
  void *pointer = lua_touserdata(L,1);
  long size = lua_tonumber(L,2);

  // convert
  THDoubleStorage *storage = THDoubleStorage_newWithData(pointer,size);

  // push on stack
  luaT_pushudata(L, storage, luaT_checktypename2id(L, "torch.DoubleStorage"));
  return 1;
}

static int DoubleStorage_to_Pointer(lua_State *L) {
  // get pointer
  THDoubleStorage *storage = luaT_checkudata(L, 1, luaT_checktypename2id(L, "torch.DoubleStorage"));

  // export to pointer
  long size = storage->size;
  void *pointer = storage->data;

  // push on stack
  lua_pushlightuserdata(L, pointer);
  lua_pushnumber(L, size);
  return 2;
}

static int Pointer_to_FloatStorage(lua_State *L) {
  // get pointer
  void *pointer = lua_touserdata(L,1);
  long size = lua_tonumber(L,2);

  // convert
  THFloatStorage *storage = THFloatStorage_newWithData(pointer,size);

  // push on stack
  luaT_pushudata(L, storage, luaT_checktypename2id(L, "torch.FloatStorage"));
  return 1;
}

static int FloatStorage_to_Pointer(lua_State *L) {
  // get pointer
  THFloatStorage *storage = luaT_checkudata(L, 1, luaT_checktypename2id(L, "torch.FloatStorage"));

  // export to pointer
  long size = storage->size;
  void *pointer = storage->data;

  // push on stack
  lua_pushlightuserdata(L, pointer);
  lua_pushnumber(L, size);
  return 2;
}

static const struct luaL_reg rawptr [] = {
  {"Pointer_to_DoubleStorage", Pointer_to_DoubleStorage},
  {"DoubleStorage_to_Pointer", DoubleStorage_to_Pointer},
  {"Pointer_to_FloatStorage", Pointer_to_FloatStorage},
  {"FloatStorage_to_Pointer", FloatStorage_to_Pointer},
  {NULL, NULL}
};

int luaopen_librawptr (lua_State *L) {
  luaL_openlib(L, "librawptr", rawptr, 0);
  return 1;
}
