#include <iostream>
#include <dlfcn.h>

template <class T>
class LoadLib
{
    private:
        void *handle = nullptr;

        T* (*create_l)() = nullptr;
        void (*destroy_l)(T*) = nullptr;

        std::string path;

    public:
        LoadLib(std::string p) : path(p) {
            this->handle = dlopen(this->path.c_str(), RTLD_LAZY | RTLD_GLOBAL);

            if (!this->handle)
                std::cerr << "[ERROR " << this->path << "] : Cannot load library" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;
            dlerror();
        };

        ~LoadLib() {
            dlclose(this->handle);
        };

        T *init() {
            this->create_l = (T *(*)()) dlsym(this->handle, "create");

            const char* dlsym_error = dlerror();
            if (dlsym_error)
                std::cerr << "[ERROR " << this->path << "] : Cannot load symbol create" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;

            this->destroy_l = (void (*)(T *)) dlsym(this->handle, "destroy");

            dlsym_error = dlerror();
            if (dlsym_error)
                std::cerr << "[ERROR " << this->path << "] : Cannot load symbol destroy" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;
            
            return (this->create_l());
        }

        void destroyLib(T *lib) {
            this->destroy_l(lib);
        }
};
