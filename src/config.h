#ifndef RABENDALIB_CONFIG
#define RABENDALIB_CONFIG

#define STR(str) #str

#define NAMESPACE_GET(name) rabendalib_##name
#define NAMESPACE_BEGIN(name) namespace NAMESPACE_GET(name) {
#define NAMESPACE_END(name) }


#endif //RABENDALIB_CONFIG
