#ifndef RABENDALIB_BASIC_RSTRING
#define RABENDALIB_BASIC_RSTRING


#include <exception>
#include <stdexcept>
#include <rabenda/lib_common.hpp>

NAMESPACE_BEGIN(basic)

template<typename CharT = char>
class RString
{
public:
	RString(){}
	~RString()
	{
		if (m_ptr != nullptr)
			delete m_ptr;
	}
	
	RString(CharT const* rhs)
		:m_ptr{new CharT[m_size = strlen(rhs)](rhs)}
	{}

	RString(CharT const* rhs, size_t len)
		:m_ptr{new CharT[len](rhs)}, m_size{len}
	{}

	RString(RString const& rhs)
		:m_ptr(new CharT[rhs.m_size](rhs.m_ptr)), m_size(rhs.m_size)
	{
		
	}

	RString& operator=(RString const& rhs) noexcept
	{
		RString tmp(rhs);
		this->swap(tmp);
		return *this;
	}

	RString& assign(RString const& rhs) noexcept
	{
		return this->operator=(rhs);
	}

	CharT& at(int index)
	{
		if (m_size <= index)
			throw std::out_of_range("Out of index");
		return this->operator[](index);
	}
	CharT const& at(int index) const
	{
		if (m_size <= index)
			throw std::out_of_range("Out of index");
		return this->operator[](index);
	}

	CharT& operator[](int index)
	{
		return m_ptr[index];
	}
	CharT const& operator[](int index) const
	{
		return m_ptr[index];
	}

	bool empty() const
	{
		return m_size == 0;
	}
	size_t size() const
	{
		return m_size;
	}
	size_t length() const
	{
		return size();
	}

	void swap(RString& rhs) noexcept
	{
		std::swap(this->m_ptr, rhs.m_ptr);
		std::swap(this->m_size, rhs.m_size);
	}


private:

	CharT* m_ptr = nullptr;
	size_t m_size = 0;
};

inline RString<> operator""_rs(char const* str, size_t len)
{
	return RString<>{str, len};
}

NAMESPACE_END(basic)

#endif
