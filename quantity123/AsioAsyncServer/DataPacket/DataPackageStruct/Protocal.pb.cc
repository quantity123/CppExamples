// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocal.proto

#include "Protocal.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class PClientLoginDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PClientLogin>
      _instance;
} _PClientLogin_default_instance_;
class PClientLoginFeedbackDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PClientLoginFeedback>
      _instance;
} _PClientLoginFeedback_default_instance_;
class PClientIsOnlineDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PClientIsOnline>
      _instance;
} _PClientIsOnline_default_instance_;
namespace protobuf_Protocal_2eproto {
static void InitDefaultsPClientLogin() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_PClientLogin_default_instance_;
    new (ptr) ::PClientLogin();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::PClientLogin::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_PClientLogin =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPClientLogin}, {}};

static void InitDefaultsPClientLoginFeedback() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_PClientLoginFeedback_default_instance_;
    new (ptr) ::PClientLoginFeedback();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::PClientLoginFeedback::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_PClientLoginFeedback =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPClientLoginFeedback}, {}};

static void InitDefaultsPClientIsOnline() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_PClientIsOnline_default_instance_;
    new (ptr) ::PClientIsOnline();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::PClientIsOnline::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_PClientIsOnline =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPClientIsOnline}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_PClientLogin.base);
  ::google::protobuf::internal::InitSCC(&scc_info_PClientLoginFeedback.base);
  ::google::protobuf::internal::InitSCC(&scc_info_PClientIsOnline.base);
}

::google::protobuf::Metadata file_level_metadata[3];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientLogin, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientLogin, loginname_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientLoginFeedback, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientLoginFeedback, success_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientIsOnline, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PClientIsOnline, online_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::PClientLogin)},
  { 6, -1, sizeof(::PClientLoginFeedback)},
  { 12, -1, sizeof(::PClientIsOnline)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_PClientLogin_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_PClientLoginFeedback_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_PClientIsOnline_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "Protocal.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\016Protocal.proto\"!\n\014PClientLogin\022\021\n\tLogi"
      "nName\030\001 \001(\t\"\'\n\024PClientLoginFeedback\022\017\n\007S"
      "uccess\030\001 \001(\010\"!\n\017PClientIsOnline\022\016\n\006Onlin"
      "e\030\001 \001(\010b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 135);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protocal.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_Protocal_2eproto

// ===================================================================

void PClientLogin::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PClientLogin::kLoginNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PClientLogin::PClientLogin()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Protocal_2eproto::scc_info_PClientLogin.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:PClientLogin)
}
PClientLogin::PClientLogin(const PClientLogin& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  loginname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.loginname().size() > 0) {
    loginname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.loginname_);
  }
  // @@protoc_insertion_point(copy_constructor:PClientLogin)
}

void PClientLogin::SharedCtor() {
  loginname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

PClientLogin::~PClientLogin() {
  // @@protoc_insertion_point(destructor:PClientLogin)
  SharedDtor();
}

void PClientLogin::SharedDtor() {
  loginname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void PClientLogin::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* PClientLogin::descriptor() {
  ::protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PClientLogin& PClientLogin::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Protocal_2eproto::scc_info_PClientLogin.base);
  return *internal_default_instance();
}


void PClientLogin::Clear() {
// @@protoc_insertion_point(message_clear_start:PClientLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  loginname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool PClientLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PClientLogin)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string LoginName = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_loginname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->loginname().data(), static_cast<int>(this->loginname().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "PClientLogin.LoginName"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PClientLogin)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PClientLogin)
  return false;
#undef DO_
}

void PClientLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PClientLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string LoginName = 1;
  if (this->loginname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->loginname().data(), static_cast<int>(this->loginname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PClientLogin.LoginName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->loginname(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:PClientLogin)
}

::google::protobuf::uint8* PClientLogin::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:PClientLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string LoginName = 1;
  if (this->loginname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->loginname().data(), static_cast<int>(this->loginname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PClientLogin.LoginName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->loginname(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PClientLogin)
  return target;
}

size_t PClientLogin::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PClientLogin)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string LoginName = 1;
  if (this->loginname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->loginname());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PClientLogin::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PClientLogin)
  GOOGLE_DCHECK_NE(&from, this);
  const PClientLogin* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PClientLogin>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PClientLogin)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PClientLogin)
    MergeFrom(*source);
  }
}

void PClientLogin::MergeFrom(const PClientLogin& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PClientLogin)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.loginname().size() > 0) {

    loginname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.loginname_);
  }
}

void PClientLogin::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PClientLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PClientLogin::CopyFrom(const PClientLogin& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PClientLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PClientLogin::IsInitialized() const {
  return true;
}

void PClientLogin::Swap(PClientLogin* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PClientLogin::InternalSwap(PClientLogin* other) {
  using std::swap;
  loginname_.Swap(&other->loginname_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata PClientLogin::GetMetadata() const {
  protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void PClientLoginFeedback::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PClientLoginFeedback::kSuccessFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PClientLoginFeedback::PClientLoginFeedback()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Protocal_2eproto::scc_info_PClientLoginFeedback.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:PClientLoginFeedback)
}
PClientLoginFeedback::PClientLoginFeedback(const PClientLoginFeedback& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  success_ = from.success_;
  // @@protoc_insertion_point(copy_constructor:PClientLoginFeedback)
}

void PClientLoginFeedback::SharedCtor() {
  success_ = false;
}

PClientLoginFeedback::~PClientLoginFeedback() {
  // @@protoc_insertion_point(destructor:PClientLoginFeedback)
  SharedDtor();
}

void PClientLoginFeedback::SharedDtor() {
}

void PClientLoginFeedback::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* PClientLoginFeedback::descriptor() {
  ::protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PClientLoginFeedback& PClientLoginFeedback::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Protocal_2eproto::scc_info_PClientLoginFeedback.base);
  return *internal_default_instance();
}


void PClientLoginFeedback::Clear() {
// @@protoc_insertion_point(message_clear_start:PClientLoginFeedback)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  success_ = false;
  _internal_metadata_.Clear();
}

bool PClientLoginFeedback::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PClientLoginFeedback)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bool Success = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &success_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PClientLoginFeedback)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PClientLoginFeedback)
  return false;
#undef DO_
}

void PClientLoginFeedback::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PClientLoginFeedback)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool Success = 1;
  if (this->success() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->success(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:PClientLoginFeedback)
}

::google::protobuf::uint8* PClientLoginFeedback::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:PClientLoginFeedback)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool Success = 1;
  if (this->success() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->success(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PClientLoginFeedback)
  return target;
}

size_t PClientLoginFeedback::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PClientLoginFeedback)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // bool Success = 1;
  if (this->success() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PClientLoginFeedback::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PClientLoginFeedback)
  GOOGLE_DCHECK_NE(&from, this);
  const PClientLoginFeedback* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PClientLoginFeedback>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PClientLoginFeedback)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PClientLoginFeedback)
    MergeFrom(*source);
  }
}

void PClientLoginFeedback::MergeFrom(const PClientLoginFeedback& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PClientLoginFeedback)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.success() != 0) {
    set_success(from.success());
  }
}

void PClientLoginFeedback::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PClientLoginFeedback)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PClientLoginFeedback::CopyFrom(const PClientLoginFeedback& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PClientLoginFeedback)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PClientLoginFeedback::IsInitialized() const {
  return true;
}

void PClientLoginFeedback::Swap(PClientLoginFeedback* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PClientLoginFeedback::InternalSwap(PClientLoginFeedback* other) {
  using std::swap;
  swap(success_, other->success_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata PClientLoginFeedback::GetMetadata() const {
  protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void PClientIsOnline::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PClientIsOnline::kOnlineFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PClientIsOnline::PClientIsOnline()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Protocal_2eproto::scc_info_PClientIsOnline.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:PClientIsOnline)
}
PClientIsOnline::PClientIsOnline(const PClientIsOnline& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  online_ = from.online_;
  // @@protoc_insertion_point(copy_constructor:PClientIsOnline)
}

void PClientIsOnline::SharedCtor() {
  online_ = false;
}

PClientIsOnline::~PClientIsOnline() {
  // @@protoc_insertion_point(destructor:PClientIsOnline)
  SharedDtor();
}

void PClientIsOnline::SharedDtor() {
}

void PClientIsOnline::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* PClientIsOnline::descriptor() {
  ::protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PClientIsOnline& PClientIsOnline::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Protocal_2eproto::scc_info_PClientIsOnline.base);
  return *internal_default_instance();
}


void PClientIsOnline::Clear() {
// @@protoc_insertion_point(message_clear_start:PClientIsOnline)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  online_ = false;
  _internal_metadata_.Clear();
}

bool PClientIsOnline::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PClientIsOnline)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bool Online = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &online_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PClientIsOnline)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PClientIsOnline)
  return false;
#undef DO_
}

void PClientIsOnline::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PClientIsOnline)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool Online = 1;
  if (this->online() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->online(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:PClientIsOnline)
}

::google::protobuf::uint8* PClientIsOnline::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:PClientIsOnline)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool Online = 1;
  if (this->online() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->online(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PClientIsOnline)
  return target;
}

size_t PClientIsOnline::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PClientIsOnline)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // bool Online = 1;
  if (this->online() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PClientIsOnline::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PClientIsOnline)
  GOOGLE_DCHECK_NE(&from, this);
  const PClientIsOnline* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PClientIsOnline>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PClientIsOnline)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PClientIsOnline)
    MergeFrom(*source);
  }
}

void PClientIsOnline::MergeFrom(const PClientIsOnline& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PClientIsOnline)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.online() != 0) {
    set_online(from.online());
  }
}

void PClientIsOnline::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PClientIsOnline)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PClientIsOnline::CopyFrom(const PClientIsOnline& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PClientIsOnline)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PClientIsOnline::IsInitialized() const {
  return true;
}

void PClientIsOnline::Swap(PClientIsOnline* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PClientIsOnline::InternalSwap(PClientIsOnline* other) {
  using std::swap;
  swap(online_, other->online_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata PClientIsOnline::GetMetadata() const {
  protobuf_Protocal_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Protocal_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::PClientLogin* Arena::CreateMaybeMessage< ::PClientLogin >(Arena* arena) {
  return Arena::CreateInternal< ::PClientLogin >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::PClientLoginFeedback* Arena::CreateMaybeMessage< ::PClientLoginFeedback >(Arena* arena) {
  return Arena::CreateInternal< ::PClientLoginFeedback >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::PClientIsOnline* Arena::CreateMaybeMessage< ::PClientIsOnline >(Arena* arena) {
  return Arena::CreateInternal< ::PClientIsOnline >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
